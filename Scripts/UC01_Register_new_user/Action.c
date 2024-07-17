Action()
{
	lr_start_transaction("01_Register_new_user");

Open_homepage();


	lr_think_time(2);

	lr_start_transaction("Click_create_new_account");
	
	web_reg_find("Text/IC=CREATE_ACCOUNT",
		LAST);
	
	web_url("register-page.html", 
		"URL=https://www.advantageonlineshopping.com/app/user/views/register-page.html", 
		"Resource=0", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_header("SOAPAction",
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_add_auto_header("Origin", 
		"https://www.advantageonlineshopping.com");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetCountriesRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("TLS_SNI", "0");

	lr_end_transaction("Click_create_new_account",LR_AUTO);

	lr_think_time(2);

	lr_start_transaction("Click_Register");

	lr_save_string(lr_eval_string("{R1}{R2}{R3}{R4}"), "random_User_name");
	lr_save_string(lr_eval_string("{R4}{R2}{R3}{R1}"), "random_Password");
	lr_save_string(lr_eval_string("{R1}{R2}{R3}{R4}{R5}{R1}{R2}{R6}{R7}"), "random_Email");
	lr_save_string(lr_eval_string("{R1}{R2}{R3}{R4}"), "random_firstName");
	lr_save_string(lr_eval_string("{R4}{R3}{R2}{R1}"), "random_lastName");
	
	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountCreateRequest");

	web_reg_find("Text/IC=New user created successfully",
		LAST);
	
	web_custom_request("AccountCreateRequest",
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/AccountCreateRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountCreateRequest xmlns=\"com.advantage.online.store.accountservice\"><accountType>USER</accountType><address></address><allowOffersPromotion>true</allowOffersPromotion><cityName></cityName><countryId>United States,us</countryId><email>{random_Email}</email>"
		"<firstName>{random_firstName}</firstName><lastName>{random_lastName}</lastName><loginName>{random_User_name}</loginName><password>{random_Password}</password><phoneNumber>22222222222</phoneNumber><stateProvince></stateProvince><zipcode></zipcode></AccountCreateRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");

	web_reg_save_param("userId",
		"LB=<ns2:userId>",
		"RB=</ns2:userId>",
		LAST);
	
	web_reg_save_param("Authorization",
		"LB/IC=<ns2:t_authorization>",
		"RB/IC=<",
		LAST);

	web_reg_find("Text/IC=Login Successful",
		LAST);
	
	web_custom_request("AccountLoginRequest",
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email>{random_Email}</email><loginPassword>{random_Password}</loginPassword><loginUser>{random_User_name}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");


web_add_header("Authorization",
		"Basic {Authorization}");

web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_reg_find("Text/IC={userId}",
		LAST);

	web_url("{userId}", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Click_Register",LR_AUTO);
	
	lr_think_time(2);
	
log_out();
	
	lr_end_transaction("01_Register_new_user",LR_AUTO);
	
	return 0;
}