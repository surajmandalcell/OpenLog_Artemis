# AOA Research Project - README

### Project Description

Algonquin College - Stall Detection System for Gliders

### Compiling

##### Build using Docker

This builds image that will compile the firmware for the OpenLog Artemis board.

```bash
docker build -t openlog .
```

This runs the container and mounts the local directory to the container's work directory.

```bash
docker run --rm -v D:\developement\work\aoa\openlog_artemis\temp:/work/Firmware/AOA_OpenLog_Artemis/build openlog
```

**OR Combine the above two commands into one if you update the files frequently and want to test the changes**

```bash
docker build -t openlog . && docker run --rm -v D:\developement\work\aoa\openlog_artemis\temp:/work/Firmware/AOA_OpenLog_Artemis/build openlog
```
