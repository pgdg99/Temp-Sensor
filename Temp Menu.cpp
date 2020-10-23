void Menu::menuA(ADC_HandleTypeDef *hadc3, TIM_HandleTypeDef *htim1, TIM_HandleTypeDef *htim2, UART_HandleTypeDef *huart1, UART_HandleTypeDef *huart3){ // Menu A
	
	bool mA = true;
	
	double avg = 0;    // ADC3
	char txt[7] = {0}; // Room for six characters plus a terminator
	int out = 0;       // S1 Out
	
	/* Menu A Modes */
	char modesA[81] = {'-','-','-','-','-','T','E','M','P','-','M','O','D','E',':','-','-','-','-','-',
					   '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
					   '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
					   '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
	
	display.print(modesA, 1); // Print Modes A	
	
	while(mA){ // Menu A Loop
		
/* --------------------------------------------------------------------------------------------------------------------*/
		
		avg = (0.017351743998745 * HAL_ADC_GetValue(hadc3)) - 4.131819632907; // ADC3 to Temp
		
		out = (int)(avg * 100); // Decimal to Int
		
		// Extract digits of number and convert them to characters
		txt[0] = '0' + (out/100000);     // Hundred thousands digit
		txt[1] = '0' + ((out/10000)%10); // Ten thousands digit
		txt[2] = '0' + ((out/1000)%10);  // Thousands digit
		txt[3] = '0' + ((out/100)%10);   // Hundreds digit
		txt[4] = '0' + ((out/10)%10);    // Tens digit
		txt[5] = '0' + (out%10);         // Ones digit
		txt[6] = 0;                       // String terminator
				
		/* Menu A Temp */
		char dataAS[21] = {'|',' ',' ',' ',' ','T','e','m','p','=',' ',txt[1],txt[2],txt[3],'.',txt[4],txt[5],' ',' ','|'};
		
		display.print(dataAS, 3); // Print Data A Temp
		
/* --------------------------------------------------------------------------------------------------------------------*/
			
		k = key.start(); // Re-check if Key is pressed
		if(k == '*'){
			mA = false; // Check for confirmation key and exit
		}
	}
}