{
  nixpkgs ? (builtins.fetchGit {
    name = "nixos-unstable-2020-11-25";
    url = "https://github.com/nixos/nixpkgs-channels/";
    # `git ls-remote https://github.com/nixos/nixpkgs-channels nixos-unstable`
    ref = "refs/heads/nixos-unstable";
    rev = "84d74ae9c9cbed73274b8e4e00be14688ffc93fe";
  })
}:

with import nixpkgs {};

stdenv.mkDerivation {
  name = "test_nix_cpp";
  src = ./.;

  nativeBuildInputs = [ cmake ninja ];
  buildInputs = [ glfw ];

  configurePhase = "cmake -G Ninja .";
  buildPhase = "ninja";
  installPhase = ''
    mkdir -p $out/bin
    cp src/tnc $out/bin/
  '';
}
