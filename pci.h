#ifndef _PCI_H_
#define _PCI_H_

/* This file provides prototypes for functions defined in pci.c which
 * are used by common.c etc.  It also forward declares functions
 * inside pci.c, thus reducing set of forward declarations needed there.
 */

/* Firmware, EEPROM, Phy */
int acxpci_upload_radio(acx_device_t *adev);

int acxpci_write_fw(acx_device_t *adev, const firmware_image_t *fw_image,
		u32 offset);
int acxpci_validate_fw(acx_device_t *adev, const firmware_image_t *fw_image,
		u32 offset);

/* CMDs (Control Path) */
int acxpci_issue_cmd_timeo_debug(acx_device_t *adev, unsigned cmd,
		void *buffer, unsigned buflen, unsigned cmd_timeout,
		const char *cmdstr);

void acxpci_init_mboxes(acx_device_t *adev);

/* Proc, Debug */
int acxpci_proc_diag_output(struct seq_file *file, acx_device_t *adev);

/* Rx Path
 * Tx Path
 */
tx_t *acxpci_alloc_tx(acx_device_t *adev);

/* Irq Handling, Timer */

/* Ioctls
 * Driver, Module
 */

#if defined(CONFIG_ACX_MAC80211_PCI)

int __init acxpci_init_module(void);
void __exit acxpci_cleanup_module(void);

void acxpci_reset_mac(acx_device_t *adev);

#else /* !CONFIG_ACX_MAC80211_PCI */

static inline int __init acxpci_init_module(void) { return 0; }
static inline void __exit acxpci_cleanup_module(void) { }

static inline void acxpci_reset_mac(acx_device_t *adev) {}

#endif /* CONFIG_ACX_MAC80211_PCI */
#endif /* _PCI_H_ */
