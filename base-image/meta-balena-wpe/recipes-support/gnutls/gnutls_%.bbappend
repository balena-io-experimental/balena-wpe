# We need to build GnuTLS with "system trust"
EXTRA_OECONF += " --with-default-trust-store-dir=/etc/ssl/certs"
