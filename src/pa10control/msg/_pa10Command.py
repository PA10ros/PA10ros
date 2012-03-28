"""autogenerated by genmsg_py from pa10Command.msg. Do not edit."""
import roslib.message
import struct

import roslib.rostime
import std_msgs.msg

class pa10Command(roslib.message.Message):
  _md5sum = "0ec791b71599e47d9c5545b896b597cb"
  _type = "pa10control/pa10Command"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
uint8 joint
bool type #0 torque, 1 velocity
duration Duration
float64 value
bool enable
bool brake
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

"""
  __slots__ = ['header','joint','type','Duration','value','enable','brake']
  _slot_types = ['Header','uint8','bool','duration','float64','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       header,joint,type,Duration,value,enable,brake
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(pa10Command, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg._Header.Header()
      if self.joint is None:
        self.joint = 0
      if self.type is None:
        self.type = False
      if self.Duration is None:
        self.Duration = roslib.rostime.Duration()
      if self.value is None:
        self.value = 0.
      if self.enable is None:
        self.enable = False
      if self.brake is None:
        self.brake = False
    else:
      self.header = std_msgs.msg._Header.Header()
      self.joint = 0
      self.type = False
      self.Duration = roslib.rostime.Duration()
      self.value = 0.
      self.enable = False
      self.brake = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2B2id2B.pack(_x.joint, _x.type, _x.Duration.secs, _x.Duration.nsecs, _x.value, _x.enable, _x.brake))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg._Header.Header()
      if self.Duration is None:
        self.Duration = roslib.rostime.Duration()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 20
      (_x.joint, _x.type, _x.Duration.secs, _x.Duration.nsecs, _x.value, _x.enable, _x.brake,) = _struct_2B2id2B.unpack(str[start:end])
      self.type = bool(self.type)
      self.enable = bool(self.enable)
      self.brake = bool(self.brake)
      self.Duration.canon()
      return self
    except struct.error as e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2B2id2B.pack(_x.joint, _x.type, _x.Duration.secs, _x.Duration.nsecs, _x.value, _x.enable, _x.brake))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg._Header.Header()
      if self.Duration is None:
        self.Duration = roslib.rostime.Duration()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 20
      (_x.joint, _x.type, _x.Duration.secs, _x.Duration.nsecs, _x.value, _x.enable, _x.brake,) = _struct_2B2id2B.unpack(str[start:end])
      self.type = bool(self.type)
      self.enable = bool(self.enable)
      self.brake = bool(self.brake)
      self.Duration.canon()
      return self
    except struct.error as e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_3I = struct.Struct("<3I")
_struct_2B2id2B = struct.Struct("<2B2id2B")
