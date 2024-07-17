Action()
{
lr_start_transaction("UC04_product_in_the_cart");

Open_homepage();

lr_think_time(2);

	log_in();
	
	lr_think_time(2);
	
open_categories_speakers();
	
	lr_think_time(2);
	
	Click_basket();

	lr_end_transaction("UC04_product_in_the_cart",LR_AUTO);

	return 0;
}