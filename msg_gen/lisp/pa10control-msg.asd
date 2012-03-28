
(cl:in-package :asdf)

(defsystem "pa10control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "pa10Status" :depends-on ("_package_pa10Status"))
    (:file "_package_pa10Status" :depends-on ("_package"))
    (:file "pa10Command" :depends-on ("_package_pa10Command"))
    (:file "_package_pa10Command" :depends-on ("_package"))
  ))