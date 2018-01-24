import os, sys

from setuptools import setup, Extension
from setuptools.command import build_ext

# for debug
#compiler = "clang++"
compiler = "gcc"
if "--enable-ccache" in sys.argv:
    # ccache
    for path in os.getenv("PATH").split(os.pathsep):
        path = path.strip('"')
        exe = os.path.join(path, "ccache")
        if os.path.isfile(exe) and os.access(exe, os.X_OK):
            os.environ["CC"] = "ccache " + compiler
            break
    sys.argv = [x for x in sys.argv if x != "--enable-ccache"]


include_dirs = [
    "../",
]
libraries = [
    # required by tippecanoe
    "m",
    "z",
    "sqlite3",
    "pthread",
    # required by Boost.Python
    "boost_python-py{}{}".format(*sys.version_info[:2]),
    "stdc++",
]
library_dirs = [
]
extras = [
    "-std=c++11",
    "-DBOOST_PYTHON_STATIC_LIB",
]

sources = [
    # from Makefile tippecanoe dependencies
    "../geojson.cpp",
    "../jsonpull/jsonpull.c",
    "../tile.cpp",
    "../pool.cpp",
    "../mbtiles.cpp",
    "../geometry.cpp",
    "../projection.cpp",
    "../memfile.cpp",
    "../mvt.cpp",
    "../serial.cpp",
    #"../main.cpp",
    "../text.cpp",
    "../dirtiles.cpp",
    "../plugin.cpp",
    "../read_json.cpp",
    "../write_json.cpp",
    "../geobuf.cpp",
    "../evaluator.cpp",
    "../geocsv.cpp",
    "../csv.cpp",
    "patched/main.cpp",
]
for (dirname, _, filenames) in os.walk("src"):
    for filename in filenames:
        if not filename.endswith(".cpp"):
            continue
        sources.append("{}/{}".format(dirname, filename))


ext = Extension(name="tippecanoe.__tippecanoe",
                include_dirs=include_dirs,
                libraries=libraries,
                library_dirs=library_dirs,
                sources=sources,
                extra_compile_args=extras,
                extra_link_args=["-fPIC"])

setup(name="tippecanoe",
      version="0.0.1",
      description="tippecanoe python wrapper",
      author="mugwort_rc",
      author_email="mugwort rc at gmail com",
      url="https://github.com/mugwort-rc/python-tippecanoe",
      classifiers=[
          "Development Status :: 3 - Alpha",
          "Intended Audience :: Developers",
          "License :: OSI Approved :: BSD License",
          "Programming Language :: C++",
          "Programming Language :: Python",
          "Programming Language :: Python :: 3.5",
      ],
      license="BSD",
      packages=["tippecanoe"],

      ext_modules=[ext]
)
