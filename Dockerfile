FROM petrosagg/resin-wpe:raspberrypi3-9416a43

COPY udev-rules/ /etc/udev/rules.d/

COPY wpe-init /wpe-init

CMD [ "/wpe-init" ]
