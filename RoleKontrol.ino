/*
	Batuhan Orhan
	bthnorhan 02/05/2017 21:15 Salı.
*/

//Röle ve buton pinlerinin tanımlanması yaptık.
const int role1 = 12, role2 = 13;
const int butonPin = 2;

//Gerekli değerler oluşturduk.
boolean role1durum = true, role2durum = true, butonBasildiMi = false;
int sayac = 0, durum = 0;
const int saniye = 3;

void setup() {
	//Röleler çıkış olarak ve aktif olarak ayarladık.
	pinMode(role1, OUTPUT);
	pinMode(role2, OUTPUT);
	digitalWrite(role1, HIGH);
	digitalWrite(role2, HIGH);

	//Butonun input_pullupı etkin hale getirildi ve interrupt olarak ayarladık.
	pinMode(butonPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(butonPin), kontrol, FALLING);
}

void loop() {
	if(butonBasildiMi){
		//Butona basıldıysa ve hala baslı tutuluyorsa sayacı 1 arttırdık.
	    if(digitalRead(butonPin) == LOW){
	    	sayac++;
	    	delay(100);
	    }
	    //Buton basılması bittiyse değişkeni false yaptık.
	   	else
	   	{
	   		butonBasildiMi = false;
	   	}
	}
	else{
		//Sayaç belirtilen saniye ile 0 arasında ise 1. durumu fonksiyona gönderdik.
		if(sayac > 0 && sayac < saniye * 10){
			durum = 1;
			roleKontrol(durum);
		}
		//Sayaç belirtilen saniyeye eşit veya daha büyükse 2. durumu fonksiyona gönderdik.
		else if(sayac >= saniye * 10){
			durum = 2;
		    roleKontrol(durum);
		}
		sayac = 0;
	}
}

/*
	1. durumda role1'in durumunu tersine çevirip aktif ise pasif ,
	pasif ise aktif durumuna getirdik.
	2. durumda role2'nin durumunu tersine çevirip aktif ise pasif,
	pasif ise aktif durumuna getirdik.
*/
void roleKontrol(int roleDurum)
{
	switch (roleDurum) {
	    case 1:
	    	role1durum = !role1durum;
	    	digitalWrite(role1, role1durum);
	    	break;
	    case 2:
	    	role2durum = !role2durum;
	    	digitalWrite(role2, role2durum);
	    	break;
	    default:
	    	digitalWrite(role1, HIGH);
	    	digitalWrite(role2, HIGH);
   			break;
	}
}

//Butona basıldığında butonBasildiMi değişkenini true olarak değiştirdik.
void kontrol() {
	butonBasildiMi = true;
}