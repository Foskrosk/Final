Action()
{
lr_start_transaction("UC05_booking_of_goods");

Open_homepage();

lr_think_time(2);

	log_in();
	
	lr_think_time(2);
	
open_categories_speakers();
	
lr_think_time(2);

product_selection();
	
lr_think_time(2);

	Click_Checkout();

	lr_end_transaction("UC05_booking_of_goods",LR_AUTO);

	return 0;
}