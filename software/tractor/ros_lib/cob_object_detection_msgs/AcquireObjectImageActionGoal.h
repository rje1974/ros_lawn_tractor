#ifndef _ROS_cob_object_detection_msgs_AcquireObjectImageActionGoal_h
#define _ROS_cob_object_detection_msgs_AcquireObjectImageActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_object_detection_msgs/AcquireObjectImageGoal.h"

namespace cob_object_detection_msgs
{

  class AcquireObjectImageActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef cob_object_detection_msgs::AcquireObjectImageGoal _goal_type;
      _goal_type goal;

    AcquireObjectImageActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/AcquireObjectImageActionGoal"; };
    const char * getMD5(){ return "5d81769387c56e38175f36d1b8297c93"; };

  };

}
#endif