google_test = dependency('gtest')

test_sources = [
#   'test_hello_world.cpp',
#   'test_milestone02.cpp',
#   'test_milestone03.cpp',
  'test_milestone04.cpp',
  'gtest_mpi_main.cpp'
]

tests = executable(
	'tests',
	test_sources,
	include_directories : [lib_incdirs],
	link_with : [lib],
	dependencies : [eigen, google_test, mpi]
)

test('Tests', tests)
