lib_sources = [  # All source files (excluding headers)
    'hello.cpp',
    'verlet.cpp',
    'xyz.cpp'
]

lib = static_library(
    'lib',  # Unique name
    lib_sources,
    dependencies : [eigen, mpi]
)

lib_incdirs = include_directories('.')
