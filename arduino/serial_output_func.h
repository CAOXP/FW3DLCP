
//Basic echo
#define	SERIAL_ECHO_STR(str)					Serial.print(str);
#define SERIAL_ECHO_STRln(str)                  Serial.println(str);
#define SERIAL_ECHO_INT_STR(dat,str)            {Serial.print(dat);Serial.println(str);}
#define SERIAL_ECHO_STR_INT(str,dat)            {Serial.print(str);Serial.println(dat);}
#define SERIAL_ECHO_STR_FLT(str,dat,seg)    	{Serial.print(str);Serial.println(dat,seg);}


// for command debug
#ifdef  CMD_DEBUG_ECHO_CMDINFO

	#define	SERIAL_DEBUG_HEAD					{SERIAL_ECHO_STR("DD:");}

    #define SERIAL_DEBUG_STR(str)               {SERIAL_DEBUG_HEAD; SERIAL_ECHO_STRln(str);}
    #define SERIAL_DEBUG_STRln(str)				{SERIAL_DEBUG_HEAD; SERIAL_ECHO_STRln(str);}
    #define SERIAL_DEBUG_INT_STR(dat,str)       {SERIAL_DEBUG_HEAD; SERIAL_ECHO_INT_STR(dat,str);}
    #define SERIAL_DEBUG_STR_INT(str,dat)       {SERIAL_DEBUG_HEAD; SERIAL_ECHO_STR_INT(str,dat);}
    #define SERIAL_DEBUG_STR_FLT(str,dat,seg)   {SERIAL_DEBUG_HEAD; SERIAL_ECHO_STR_FLT(str,dat,seg);}
#else
    #define SERIAL_DEBUG_STR(str)    			
    #define SERIAL_DEBUG_STRln(str)
    #define SERIAL_DEBUG_INT_STR(dat,str)
    #define SERIAL_DEBUG_STR_INT(str,dat)             
    #define SERIAL_DEBUG_STR_FLT(str,dat,seg)         
#endif

// for error output
#ifdef	CMD_ERROR_OUTPUT
	#define SERIAL_ERROR_STR(str)       		SERIAL_ECHO_STRln(str)
#else
	#define SERIAL_ERROR_STR(str)
#endif


// for command response
#define	SERIAL_CMD_ACK(str)						SERIAL_ECHO_STRln(str)


