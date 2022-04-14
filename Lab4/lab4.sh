DISC="sda"; \
 cat /sys/block/$DISC/queue/scheduler; \
 for T in mq-deadline bfq kyber none; do \
     sudo echo $T | sudo tee /sys/block/$DISC/queue/scheduler; \
     sudo cat /sys/block/$DISC/queue/scheduler; \
     sudo sync && /sbin/hdparm -tT /dev/$DISC && echo "----"; \
     sleep 15; \
 done