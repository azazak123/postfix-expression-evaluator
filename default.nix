{ lib
, llvmPackages_11
, cmake
}:

llvmPackages_11.stdenv.mkDerivation rec {
  pname = "Postfix-expression-evaluator";
  version = "0.1.0";
  
  src = ./.;

  nativeBuildInputs = [ cmake ];
  buildInputs = [ ];

  cmakeFlags = [
    "-DENABLE_TESTING=OFF"
    "-DENABLE_INSTALL=ON"
  ];
}
