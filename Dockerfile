FROM petrosagg/resin-wpe:raspberrypi3-06da0ed

COPY udev-rules/ /etc/udev/rules.d/

COPY wpe-init /wpe-init

CMD [ "/wpe-init" ]
