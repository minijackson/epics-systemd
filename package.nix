{ mkEpicsPackage, pkg-config, systemdMinimal }:

mkEpicsPackage {
  pname = "epics-systemd";
  version = "0.1.0";
  varname = "EPICS_SYSTEMD";

  nativeBuildInputs = [ pkg-config ];
  buildInputs = [ systemdMinimal ];

  src = ./.;
}
