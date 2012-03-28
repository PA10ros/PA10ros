FILE(REMOVE_RECURSE
  "../msg_gen"
  "../src/pa10control/msg"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/pa10control/msg/__init__.py"
  "../src/pa10control/msg/_pa10Status.py"
  "../src/pa10control/msg/_pa10Command.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
