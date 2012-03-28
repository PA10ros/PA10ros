; Auto-generated. Do not edit!


(cl:in-package pa10control-msg)


;//! \htmlinclude pa10Command.msg.html

(cl:defclass <pa10Command> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (joint
    :reader joint
    :initarg :joint
    :type cl:fixnum
    :initform 0)
   (type
    :reader type
    :initarg :type
    :type cl:boolean
    :initform cl:nil)
   (Duration
    :reader Duration
    :initarg :Duration
    :type cl:real
    :initform 0)
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0)
   (enable
    :reader enable
    :initarg :enable
    :type cl:boolean
    :initform cl:nil)
   (brake
    :reader brake
    :initarg :brake
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass pa10Command (<pa10Command>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pa10Command>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pa10Command)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pa10control-msg:<pa10Command> is deprecated: use pa10control-msg:pa10Command instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:header-val is deprecated.  Use pa10control-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'joint-val :lambda-list '(m))
(cl:defmethod joint-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:joint-val is deprecated.  Use pa10control-msg:joint instead.")
  (joint m))

(cl:ensure-generic-function 'type-val :lambda-list '(m))
(cl:defmethod type-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:type-val is deprecated.  Use pa10control-msg:type instead.")
  (type m))

(cl:ensure-generic-function 'Duration-val :lambda-list '(m))
(cl:defmethod Duration-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:Duration-val is deprecated.  Use pa10control-msg:Duration instead.")
  (Duration m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:value-val is deprecated.  Use pa10control-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'enable-val :lambda-list '(m))
(cl:defmethod enable-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:enable-val is deprecated.  Use pa10control-msg:enable instead.")
  (enable m))

(cl:ensure-generic-function 'brake-val :lambda-list '(m))
(cl:defmethod brake-val ((m <pa10Command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:brake-val is deprecated.  Use pa10control-msg:brake instead.")
  (brake m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pa10Command>) ostream)
  "Serializes a message object of type '<pa10Command>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'joint)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'type) 1 0)) ostream)
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'Duration)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'Duration) (cl:floor (cl:slot-value msg 'Duration)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'enable) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'brake) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pa10Command>) istream)
  "Deserializes a message object of type '<pa10Command>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'joint)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'type) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Duration) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'enable) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'brake) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pa10Command>)))
  "Returns string type for a message object of type '<pa10Command>"
  "pa10control/pa10Command")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pa10Command)))
  "Returns string type for a message object of type 'pa10Command"
  "pa10control/pa10Command")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pa10Command>)))
  "Returns md5sum for a message object of type '<pa10Command>"
  "0ec791b71599e47d9c5545b896b597cb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pa10Command)))
  "Returns md5sum for a message object of type 'pa10Command"
  "0ec791b71599e47d9c5545b896b597cb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pa10Command>)))
  "Returns full string definition for message of type '<pa10Command>"
  (cl:format cl:nil "Header header~%uint8 joint~%bool type #0 torque, 1 velocity~%duration Duration~%float64 value~%bool enable~%bool brake~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pa10Command)))
  "Returns full string definition for message of type 'pa10Command"
  (cl:format cl:nil "Header header~%uint8 joint~%bool type #0 torque, 1 velocity~%duration Duration~%float64 value~%bool enable~%bool brake~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pa10Command>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     8
     8
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pa10Command>))
  "Converts a ROS message object to a list"
  (cl:list 'pa10Command
    (cl:cons ':header (header msg))
    (cl:cons ':joint (joint msg))
    (cl:cons ':type (type msg))
    (cl:cons ':Duration (Duration msg))
    (cl:cons ':value (value msg))
    (cl:cons ':enable (enable msg))
    (cl:cons ':brake (brake msg))
))
