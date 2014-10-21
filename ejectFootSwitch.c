// http://blog.kamabokonet.com/2014/09/08/eject%E5%85%89%E5%AD%A6%E3%83%89%E3%83%A9%E3%82%A4%E3%83%96%E3%81%AE%E9%96%8B%E9%96%89%E7%8A%B6%E6%85%8B%E3%82%92%E5%8F%96%E5%BE%97%E3%81%97%E3%81%A6%E3%81%BF%E3%82%8B/ より拝借
// kamaboko thank you
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/cdrom.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
int main(int argc,char *argv[]){
    int fd, result, slot;
    
    if(argc != 2){
        printf("ERROR!\n");
        return(-1);
    }
    
    fd = open(argv[1], O_RDONLY | O_NONBLOCK);
    result=ioctl(fd, CDROM_DRIVE_STATUS, slot);
 
    close(fd);
 
    switch(result) {
        case CDS_NO_INFO:
            printf("NO_INFOMATIONn");
            return(0);
 
        case CDS_NO_DISC:
            printf("NO_DISCn");
            
            /* write whatever you want to do */
            char *bootApp = "アプリケーション名";
            char *checkApp = "pgrep -f 'アプリケーション名'";
            char *killApp = "pgrep -f 'アプリケーション名' | xargs kill";
            /* example */
            // char *bootApp = "ruby mikutter";
            // char *checkApp = "pgrep -f 'mikutter'";
            // char *killApp = "pgrep -f 'mikutter' | xargs kill";
            /* example ends here */
            
            /* not yet worked */
            // if(WEXITSTATUS(system(checkApp)) == 0){
            //  system(bootApp);
            // }
            // else
            // {
            //  system(killApp);
            // }
            
            char *eject = "eject";
            printf("uiiiin\n");
            system(eject);
            return EXIT_SUCCESS;
            return(1);
 
        case CDS_TRAY_OPEN:
            printf("TRAY_OPEN\n");
            return(2);
 
        case CDS_DRIVE_NOT_READY:
            printf("NOT_READY\n");
            return(3);
 
        case CDS_DISC_OK:
            printf("DISC_OK\n");
            return(4);
 
        default:
            printf("ERROR!\n");
            return(-1);
    }
}
