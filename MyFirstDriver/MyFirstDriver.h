
#define IOCTL_FIRST_CODE CTL_CODE(0x8000, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_SECOND_CODE CTL_CODE(0x8000, 0x801, METHOD_NEITHER, FILE_ANY_ACCESS)

#define DRIVER_FUNC_INSTALL     0x01
#define DRIVER_FUNC_REMOVE      0x02

#define DRIVER_NAME       "MyFirstDriver"
