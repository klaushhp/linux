#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/init.h>
#include <linux/skbuff.h>
#include <linux/spinlock.h>
#include <linux/crc32.h>
#include <linux/mii.h>
#include <linux/ethtool.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/irq.h>
#include <linux/slab.h>

#include <asm/delay.h>
#include <asm/irq.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");
struct net_device *fs_dev;
netdev_tx_t 	vndo_start_xmit (struct sk_buff *skb,
					   struct net_device *dev)
{


  static   int count  = 0;

  printk("count  = %d\n",++count);
  fs_dev->stats.tx_packets  ++;
  fs_dev->stats.tx_aborted_errors  ++;
  fs_dev->stats.tx_bytes ++;
  fs_dev->stats.tx_carrier_errors  ++;
  fs_dev->stats.tx_heartbeat_errors++;
  	  

    return   0;


}

struct net_device_ops vnetdev_ops  = {

     .ndo_start_xmit  = vndo_start_xmit,


};

int  vnet_init(void)
{

  fs_dev  = alloc_netdev(0, "vnet%d", ether_setup);

  fs_dev->netdev_ops  = &vnetdev_ops;
  fs_dev->dev_addr[0]  = 0x00;
  fs_dev->dev_addr[1]  = 0x01;
  fs_dev->dev_addr[2]  = 0x02;
  fs_dev->dev_addr[3]  = 0x03;
  fs_dev->dev_addr[4]  = 0x04;
  fs_dev->dev_addr[5]  = 0x05;
  
  register_netdev(fs_dev);
  printk("vnet_init  \n");
  return  0;
}

void  vnet_exit(void)
{
	unregister_netdev(fs_dev);

	free_netdev(fs_dev);

   printk("vnet_exit  \n");
}
module_init(vnet_init);
module_exit(vnet_exit);
