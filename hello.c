#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// macros for marking up functions e.g. __init
// core header for loading LKMs
// contains kernel types, macros, functions
MODULE_LICENSE("GPL");

// the license type (affects behavior)
MODULE_AUTHOR("Derek Molloy"); // The author visible with modinfo
MODULE_DESCRIPTION("A simple Linux LKM for the RPi."); // desc.
MODULE_VERSION("0.1");

// the version of the module
static char *name = "world"; // example LKM argument default is "world"

// param description charp = char pointer, defaults to "world"
module_param(name, charp, S_IRUGO); // S_IRUGO can be read/not changed
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

/** @brief The LKM initialization function
* The static keyword restricts the visibility of the function to within
* this C file. The __init macro means that for a built-in driver (not
* an LKM) the function is only used at initialization time and that it
* can be discarded and its memory freed up after that point.
* @return returns 0 if successful
*/
static int __init helloERPi_init(void) {
	printk(KERN_INFO "ERPi: Hello %s from the RPi LKM!\n", name);
	return 0;
}

/** @brief The LKM cleanup function
* Similar to the initialization function, it is static. The __exit
* macro establishes that if this code is used for a built-in driver (not
* an LKM) that this function is not required.
*/
static void __exit helloERPi_exit(void) {
	printk(KERN_INFO "ERPi: Goodbye %s from the RPi LKM!\n", name);
}

/** @brief A module must use the module_init() module_exit() macros from
* linux/init.h, which identify the initialization function at insertion
* time and the cleanup function (as listed above).
*/
module_init(helloERPi_init);
module_exit(helloERPi_exit);
