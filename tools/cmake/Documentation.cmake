# Documentation target
set(DOCUMENTATION_TARGET Documentation)
add_custom_target(
  ${DOCUMENTATION_TARGET}
  COMMAND doxygen
  COMMENT "Generate documentation"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
)
