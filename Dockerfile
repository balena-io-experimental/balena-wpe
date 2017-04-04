FROM petrosagg/resin-wpe:raspberrypi3-4156a6b-dirty

COPY udev-rules/ /etc/udev/rules.d/

COPY wpe-init /wpe-init

CMD [ "/wpe-init" ]
