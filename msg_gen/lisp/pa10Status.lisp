; Auto-generated. Do not edit!


(cl:in-package pa10control-msg)


;//! \htmlinclude pa10Status.msg.html

(cl:defclass <pa10Status> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (alarmCode
    :reader alarmCode
    :initarg :alarmCode
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 7 :element-type 'cl:fixnum :initial-element 0))
   (enabledAxes
    :reader enabledAxes
    :initarg :enabledAxes
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 7 :element-type 'cl:boolean :initial-element cl:nil))
   (position
    :reader position
    :initarg :position
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0))
   (velocity
    :reader velocity
    :initarg :velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0))
   (torque
    :reader torque
    :initarg :torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass pa10Status (<pa10Status>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pa10Status>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pa10Status)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pa10control-msg:<pa10Status> is deprecated: use pa10control-msg:pa10Status instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:header-val is deprecated.  Use pa10control-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'alarmCode-val :lambda-list '(m))
(cl:defmethod alarmCode-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:alarmCode-val is deprecated.  Use pa10control-msg:alarmCode instead.")
  (alarmCode m))

(cl:ensure-generic-function 'enabledAxes-val :lambda-list '(m))
(cl:defmethod enabledAxes-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:enabledAxes-val is deprecated.  Use pa10control-msg:enabledAxes instead.")
  (enabledAxes m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:position-val is deprecated.  Use pa10control-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:velocity-val is deprecated.  Use pa10control-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'torque-val :lambda-list '(m))
(cl:defmethod torque-val ((m <pa10Status>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pa10control-msg:torque-val is deprecated.  Use pa10control-msg:torque instead.")
  (torque m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pa10Status>) ostream)
  "Serializes a message object of type '<pa10Status>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'alarmCode))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'enabledAxes))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'velocity))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'torque))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pa10Status>) istream)
  "Deserializes a message object of type '<pa10Status>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'alarmCode) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'alarmCode)))
    (cl:dotimes (i 7)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'enabledAxes) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'enabledAxes)))
    (cl:dotimes (i 7)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
  (cl:setf (cl:slot-value msg 'position) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'position)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'velocity) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'velocity)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'torque) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'torque)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pa10Status>)))
  "Returns string type for a message object of type '<pa10Status>"
  "pa10control/pa10Status")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pa10Status)))
  "Returns string type for a message object of type 'pa10Status"
  "pa10control/pa10Status")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pa10Status>)))
  "Returns md5sum for a message object of type '<pa10Status>"
  "e56ad4b4432858c0c1d2f803ffcfd271")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pa10Status)))
  "Returns md5sum for a message object of type 'pa10Status"
  "e56ad4b4432858c0c1d2f803ffcfd271")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pa10Status>)))
  "Returns full string definition for message of type '<pa10Status>"
  (cl:format cl:nil "Header header~%uint16[7] alarmCode~%bool[7] enabledAxes~%float64[7] position~%float64[7] velocity~%float64[7] torque~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pa10Status)))
  "Returns full string definition for message of type 'pa10Status"
  (cl:format cl:nil "Header header~%uint16[7] alarmCode~%bool[7] enabledAxes~%float64[7] position~%float64[7] velocity~%float64[7] torque~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pa10Status>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'alarmCode) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'enabledAxes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pa10Status>))
  "Converts a ROS message object to a list"
  (cl:list 'pa10Status
    (cl:cons ':header (header msg))
    (cl:cons ':alarmCode (alarmCode msg))
    (cl:cons ':enabledAxes (enabledAxes msg))
    (cl:cons ':position (position msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':torque (torque msg))
))
