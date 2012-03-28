/* Auto-generated by genmsg_cpp for file /home/dellux09/ros_workspace/pa10control/msg/pa10Status.msg */
#ifndef PA10CONTROL_MESSAGE_PA10STATUS_H
#define PA10CONTROL_MESSAGE_PA10STATUS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace pa10control
{
template <class ContainerAllocator>
struct pa10Status_ {
  typedef pa10Status_<ContainerAllocator> Type;

  pa10Status_()
  : header()
  , alarmCode()
  , enabledAxes()
  , position()
  , velocity()
  , torque()
  {
    alarmCode.assign(0);
    enabledAxes.assign(false);
    position.assign(0.0);
    velocity.assign(0.0);
    torque.assign(0.0);
  }

  pa10Status_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , alarmCode()
  , enabledAxes()
  , position()
  , velocity()
  , torque()
  {
    alarmCode.assign(0);
    enabledAxes.assign(false);
    position.assign(0.0);
    velocity.assign(0.0);
    torque.assign(0.0);
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef boost::array<uint16_t, 7>  _alarmCode_type;
  boost::array<uint16_t, 7>  alarmCode;

  typedef boost::array<uint8_t, 7>  _enabledAxes_type;
  boost::array<uint8_t, 7>  enabledAxes;

  typedef boost::array<double, 7>  _position_type;
  boost::array<double, 7>  position;

  typedef boost::array<double, 7>  _velocity_type;
  boost::array<double, 7>  velocity;

  typedef boost::array<double, 7>  _torque_type;
  boost::array<double, 7>  torque;


  ROS_DEPRECATED uint32_t get_alarmCode_size() const { return (uint32_t)alarmCode.size(); }
  ROS_DEPRECATED uint32_t get_enabledAxes_size() const { return (uint32_t)enabledAxes.size(); }
  ROS_DEPRECATED uint32_t get_position_size() const { return (uint32_t)position.size(); }
  ROS_DEPRECATED uint32_t get_velocity_size() const { return (uint32_t)velocity.size(); }
  ROS_DEPRECATED uint32_t get_torque_size() const { return (uint32_t)torque.size(); }
private:
  static const char* __s_getDataType_() { return "pa10control/pa10Status"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "e56ad4b4432858c0c1d2f803ffcfd271"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "Header header\n\
uint16[7] alarmCode\n\
bool[7] enabledAxes\n\
float64[7] position\n\
float64[7] velocity\n\
float64[7] torque\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, header);
    ros::serialization::serialize(stream, alarmCode);
    ros::serialization::serialize(stream, enabledAxes);
    ros::serialization::serialize(stream, position);
    ros::serialization::serialize(stream, velocity);
    ros::serialization::serialize(stream, torque);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, header);
    ros::serialization::deserialize(stream, alarmCode);
    ros::serialization::deserialize(stream, enabledAxes);
    ros::serialization::deserialize(stream, position);
    ros::serialization::deserialize(stream, velocity);
    ros::serialization::deserialize(stream, torque);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(header);
    size += ros::serialization::serializationLength(alarmCode);
    size += ros::serialization::serializationLength(enabledAxes);
    size += ros::serialization::serializationLength(position);
    size += ros::serialization::serializationLength(velocity);
    size += ros::serialization::serializationLength(torque);
    return size;
  }

  typedef boost::shared_ptr< ::pa10control::pa10Status_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pa10control::pa10Status_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct pa10Status
typedef  ::pa10control::pa10Status_<std::allocator<void> > pa10Status;

typedef boost::shared_ptr< ::pa10control::pa10Status> pa10StatusPtr;
typedef boost::shared_ptr< ::pa10control::pa10Status const> pa10StatusConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::pa10control::pa10Status_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::pa10control::pa10Status_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace pa10control

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::pa10control::pa10Status_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::pa10control::pa10Status_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::pa10control::pa10Status_<ContainerAllocator> > {
  static const char* value() 
  {
    return "e56ad4b4432858c0c1d2f803ffcfd271";
  }

  static const char* value(const  ::pa10control::pa10Status_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xe56ad4b4432858c0ULL;
  static const uint64_t static_value2 = 0xc1d2f803ffcfd271ULL;
};

template<class ContainerAllocator>
struct DataType< ::pa10control::pa10Status_<ContainerAllocator> > {
  static const char* value() 
  {
    return "pa10control/pa10Status";
  }

  static const char* value(const  ::pa10control::pa10Status_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::pa10control::pa10Status_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
uint16[7] alarmCode\n\
bool[7] enabledAxes\n\
float64[7] position\n\
float64[7] velocity\n\
float64[7] torque\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::pa10control::pa10Status_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::pa10control::pa10Status_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::pa10control::pa10Status_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::pa10control::pa10Status_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.alarmCode);
    stream.next(m.enabledAxes);
    stream.next(m.position);
    stream.next(m.velocity);
    stream.next(m.torque);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct pa10Status_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pa10control::pa10Status_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::pa10control::pa10Status_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "alarmCode[]" << std::endl;
    for (size_t i = 0; i < v.alarmCode.size(); ++i)
    {
      s << indent << "  alarmCode[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.alarmCode[i]);
    }
    s << indent << "enabledAxes[]" << std::endl;
    for (size_t i = 0; i < v.enabledAxes.size(); ++i)
    {
      s << indent << "  enabledAxes[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.enabledAxes[i]);
    }
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.position[i]);
    }
    s << indent << "velocity[]" << std::endl;
    for (size_t i = 0; i < v.velocity.size(); ++i)
    {
      s << indent << "  velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.velocity[i]);
    }
    s << indent << "torque[]" << std::endl;
    for (size_t i = 0; i < v.torque.size(); ++i)
    {
      s << indent << "  torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.torque[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // PA10CONTROL_MESSAGE_PA10STATUS_H
