FROM petrosagg/resin-wpe:raspberrypi3-42bbb24

COPY udev-rules/ /etc/udev/rules.d/

COPY wpe-init /wpe-init

CMD [ "/wpe-init" ]
