# PYTHIA configuration file.
# Generated on Fri Feb 15 12:25:42 PET 2019 with the user supplied options:
# --with-hepmc2=/Users/davidromeroabad/Documents/MADGRAPH/MG5_aMC_v2_6_4/HEPTools/hepmc

# Install directory prefixes.
PREFIX_BIN=/Users/davidromeroabad/Documents/pythia8240/bin
PREFIX_INCLUDE=/Users/davidromeroabad/Documents/pythia8240/include
PREFIX_LIB=/Users/davidromeroabad/Documents/pythia8240/lib
PREFIX_SHARE=/Users/davidromeroabad/Documents/pythia8240/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
ENABLE_SHARED=false
CXX=g++
CXX_COMMON=-O2  -pedantic -W -Wall -Wshadow -fPIC
CXX_SHARED=-dynamiclib
CXX_SONAME=-Wl,-dylib_install_name,@rpath/
LIB_SUFFIX=.dylib

# EVTGEN configuration.
EVTGEN_USE=false
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

# FASTJET3 configuration.
FASTJET3_USE=false
FASTJET3_BIN=
FASTJET3_INCLUDE=
FASTJET3_LIB=

# HEPMC2 configuration.
HEPMC2_USE=true
HEPMC2_BIN=/Users/davidromeroabad/Documents/MADGRAPH/MG5_aMC_v2_6_4/HEPTools/hepmc/bin
HEPMC2_INCLUDE=/Users/davidromeroabad/Documents/MADGRAPH/MG5_aMC_v2_6_4/HEPTools/hepmc/include
HEPMC2_LIB=/Users/davidromeroabad/Documents/MADGRAPH/MG5_aMC_v2_6_4/HEPTools/hepmc/lib

# HEPMC3 configuration.
HEPMC3_USE=false
HEPMC3_BIN=
HEPMC3_INCLUDE=
HEPMC3_LIB=

# LHAPDF5 configuration.
LHAPDF5_USE=false
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

# LHAPDF6 configuration.
LHAPDF6_USE=true
LHAPDF6_BIN=/Users/davidromeroabad/Documents/LHAPDF621/bin
LHAPDF6_INCLUDE=/Users/davidromeroabad/Documents/LHAPDF621/include
LHAPDF6_LIB=/usr/local/lib

# POWHEG configuration.
POWHEG_USE=false
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

# PROMC configuration.
PROMC_USE=false
PROMC_BIN=
PROMC_INCLUDE=
PROMC_LIB=

# ROOT configuration.
ROOT_USE=false
ROOT_BIN=
ROOT_LIBS=
CXX_ROOT=

# GZIP configuration.
GZIP_USE=false
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

# BOOST configuration.
BOOST_USE=false
BOOST_BIN=
BOOST_INCLUDE=
BOOST_LIB=

# PYTHON configuration.
PYTHON_USE=false
PYTHON_BIN=
PYTHON_INCLUDE=
PYTHON_LIB=
