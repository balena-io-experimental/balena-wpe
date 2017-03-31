FROM petrosagg/raspberrypi3-wpe

COPY wpe-init /wpe-init

CMD [ "/wpe-init" ]
