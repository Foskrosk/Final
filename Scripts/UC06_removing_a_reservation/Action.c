Action()
{
lr_start_transaction("UC06_removing_a_reservation");

Open_homepage();

lr_think_time(2);

	log_in();
	
	lr_think_time(2);
	
	Click_basket();

lr_think_time(2);

lr_start_transaction("Click_Remove");

	web_set_sockets_option("TLS_SNI", "1");

	web_add_header("Authorization",
		"Basic {Authorization}");
	
	web_add_header("Origin",
		"https://www.advantageonlineshopping.com");
	
	web_reg_find("Text/IC={userId}",
		LAST);

	web_custom_request("414141",
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}/product/20/color/414141", 
		"Method=DELETE", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("Click_Remove",LR_AUTO);

	lr_end_transaction("UC06_removing_a_reservation",LR_AUTO);
	
	return 0;
}