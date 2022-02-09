{
  description = "Systemd-related facilities for EPICS IOCs";

  inputs.nixpkgs = {
    url = "github:NixOS/nixpkgs/nixos-21.11";
    follows = "epnix/nixpkgs";
  };
  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.epnix.url = "git+ssh://git@drf-gitlab.cea.fr/EPICS/epnix/epnix.git";

  outputs = { self, nixpkgs, flake-utils, epnix, ... } @ inputs:
    (flake-utils.lib.eachSystem [ "x86_64-linux" ] (system:
      let pkgs = import nixpkgs.outPath {
        inherit system;
        overlays = [ epnix.overlay self.overlay ];
      };
      in
      {
        defaultPackage = pkgs.epics-systemd;
      })) // {

      overlay = final: prev: {
        epics-systemd = prev.callPackage ./package.nix { };
      };

    };
}
