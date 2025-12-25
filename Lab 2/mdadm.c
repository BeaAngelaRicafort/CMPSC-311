/* Author: Bea Angela Ricafort
   Date: 2/23/25
    */

/***
 *      ______ .___  ___. .______     _______.  ______        ____    __   __
 *     /      ||   \/   | |   _  \   /       | /      |      |___ \  /_ | /_ |
 *    |  ,----'|  \  /  | |  |_)  | |   (----`|  ,----'        __) |  | |  | |
 *    |  |     |  |\/|  | |   ___/   \   \    |  |            |__ <   | |  | |
 *    |  `----.|  |  |  | |  |   .----)   |   |  `----.       ___) |  | |  | |
 *     \______||__|  |__| | _|   |_______/     \______|      |____/   |_|  |_|
 *
 */

#include "mdadm.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "jbod.h"
#include "util.h"


int mount = 0;

uint32_t make_op(uint32_t command, uint32_t block_id, uint32_t disk_id) {
        return command | block_id << 24 | disk_id << 20;
}

int mdadm_mount(void) {
	if (mount == 0) { // Unmounted Disk
		jbod_operation(make_op(JBOD_MOUNT, 0, 0), NULL); // Mounts Disk
		mount = 1;
		return 1;
	}
  	return -1; // Mounted Disk (Fail)
}

int mdadm_unmount(void) {
  	if (mount == 1) { // Mounted Disk
                jbod_operation(make_op(JBOD_UNMOUNT, 0, 0), NULL); // Unmounts Disk
                mount = 0;
                return 1;
        }
  	return -1; // Unmounted Disk (Fail)
}

int mdadm_read(uint32_t addr, uint32_t len, uint8_t *buf) {
	if (mount == 0) { // Unmounted Disk (Fail)
		return -1;
	}

	if ((len != 0) && (buf == NULL)) { // Null Pointer, Non-Zero Length (Fail)
		return -1;
	}

	if (len > 1024) { // Too Long (Fail)
		return -1;
	}

	if ((addr + len) > 1048575) { // Out-of-Bound Linear Address (Fail)
		return -1;
	}

	int total_bytes_read = 0;
	uint8_t temp_buff[JBOD_BLOCK_SIZE];

	while (total_bytes_read < len) {
		uint8_t offset = (addr % JBOD_DISK_SIZE) % JBOD_BLOCK_SIZE; // Finding Offset (Starting Value)
		uint32_t block_id = (addr % JBOD_DISK_SIZE) / JBOD_BLOCK_SIZE; // Finding Block ID
        	uint32_t disk_id = addr / JBOD_DISK_SIZE; // Finding Disk ID

		uint32_t seek_to_disk = make_op(JBOD_SEEK_TO_DISK, 0, disk_id); // Locating Disk
		if (jbod_operation(seek_to_disk, NULL) != 0) { // Failed to Seek to Disk
			return -1;
		}

		uint32_t seek_to_block = make_op(JBOD_SEEK_TO_BLOCK, block_id, 0); // Locating Block
		if (jbod_operation(seek_to_block, NULL) != 0) { // Failed to Seek to Block
			return -1;
                }

		uint32_t read_block = make_op(JBOD_READ_BLOCK, 0, 0); // Make Read Command
		if (jbod_operation(read_block, temp_buff) != 0) { // Failed to Read
			return -1;
		}

		int bytes_read = JBOD_BLOCK_SIZE - offset; // Number of Bytes Read in Current Iteration of While Loop
		if (len - total_bytes_read < bytes_read) { // No Buffer Overflow
			bytes_read = len - total_bytes_read;
		}

		memcpy(buf + total_bytes_read, temp_buff + offset, bytes_read);

		total_bytes_read += bytes_read;
		addr += bytes_read;

		}

	return total_bytes_read;

}

/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
/*CWD /home/cmpsc311/cmpsc311/assignments/sp2-lab2-BeaAngelaRicafort */
