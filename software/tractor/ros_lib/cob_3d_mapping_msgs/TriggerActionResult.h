#ifndef _ROS_cob_3d_mapping_msgs_TriggerActionResult_h
#define _ROS_cob_3d_mapping_msgs_TriggerActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_3d_mapping_msgs/TriggerResult.h"

namespace cob_3d_mapping_msgs
{

  class TriggerActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef cob_3d_mapping_msgs::TriggerResult _result_type;
      _result_type result;

    TriggerActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_3d_mapping_msgs/TriggerActionResult"; };
    const char * getMD5(){ return "9d927c58f7819a6901de576111376444"; };

  };

}
#endif