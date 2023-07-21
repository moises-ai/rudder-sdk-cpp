#include "rudder/message.h"

#include "rudder/utils.h"

namespace rudder {
    Message::Message(MessageType type) : mMessageType(type) {}

    MessageType Message::getType() const {
        return mMessageType;
    }

    void Message::insertTimestamp() {
#ifdef RUDDER_INSERT_TIMESTAMP
        mTimestamp = Timestamp::now();
#endif
    }
    
    void Message::validateUserId() const {
        if (!mUserId.has_value() && !mAnonymousId.has_value()) {
            throw std::runtime_error("Only one user should be assigned at a time");
        }
    }
    
    void Message::validateAndUpdateContext() {
        if (mContext.has_value() && hasReservedKeys(mContext.value())) {
            throw std::runtime_error("Context should not use reserved keys");
        }
        
        mContext->update(getDefaultContext());
    }
} // namespace rudder;
