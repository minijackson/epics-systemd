{ lib, epnixLib, mkEpicsPackage, pkg-config, systemdMinimal }:

mkEpicsPackage {
  pname = "epics-systemd";
  version = "0.1.0";
  varname = "EPICS_SYSTEMD";

  nativeBuildInputs = [ pkg-config ];
  buildInputs = [ systemdMinimal ];

  src = ./.;

  meta = {
    description = "Systemd-related facilities for EPICS IOCs";
    homepage = "https://github.com/minijackson/epics-systemd";
    license = lib.licenses.mit;
    maintainers = with epnixLib.maintainers; [ minijackson ];
  };
}
