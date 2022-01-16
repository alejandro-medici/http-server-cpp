
# {hash}
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /lithium/cmake)

project(lithium_server)

find_package(MYSQL REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED context)

include_directories(${SQLite3_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS} ${MYSQL_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR} ${PostgreSQL_INCLUDE_DIRS})

set(LIBS ${SQLite3_LIBRARIES} ${CURL_LIBRARIES} 
          ${MYSQL_LIBRARY} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}
          ${PostgreSQL_LIBRARIES} ${OPENSSL_LIBRARIES})

add_custom_target(
    symbols_generation
    COMMAND li_symbol_generator /workspaces/http-server-cpp/)

function(li_add_executable target_name)
  add_executable(${target_name} ${ARGN})
  target_link_libraries(${target_name} ${LIBS})
  add_dependencies(${target_name} symbols_generation)
  # target_precompile_headers(${target_name}  REUSE_FROM precompiled_header_target)
endfunction(li_add_executable)

li_add_executable(lithium_server /workspaces/http-server-cpp/app.cpp )
target_link_libraries(lithium_server ${LIBS})
