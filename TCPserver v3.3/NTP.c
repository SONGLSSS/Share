typedef struct {
//	char LI_VN_MODE;
//	char Stratum;
//	char Poll_Precision;
//	int Root_delay;
//	int Reference indentifier;
	
	unsigned int LV:2;
	unsigned int VN:3;
	unsigned int Mode:3;
	char Stratum;
	char Poll;
	char Precision;
	unsigned Root_delay;
	unsigned Root_dispersion;
	long Reference_timestamp;
	long Originate timestamp;
	long Receive_timestamp;
	long Transmit_timestamp;
	int Authenticator[3];

}ntp_time;
