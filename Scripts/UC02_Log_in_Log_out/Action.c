Action()
{
lr_start_transaction("UC02_Log_in_Log_out");
	
Open_homepage();

lr_think_time(2);

log_in();

lr_think_time(2);

log_out();

lr_end_transaction("UC02_Log_in_Log_out",LR_AUTO);
	return 0;
}