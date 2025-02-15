#ifndef _ROS_cob_3d_mapping_msgs_TableObjectClusterActionResult_h
#define _ROS_cob_3d_mapping_msgs_TableObjectClusterActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_3d_mapping_msgs/TableObjectClusterResult.h"

namespace cob_3d_mapping_msgs
{

  class TableObjectClusterActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef cob_3d_mapping_msgs::TableObjectClusterResult _result_type;
      _result_type result;

    TableObjectClusterActionResult():
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

    const char * getType(){ return "cob_3d_mapping_msgs/TableObjectClusterActionResult"; };
    const char * getMD5(){ return "e9a500864cad0f17b191d7e31020df77"; };

  };

}
#endif