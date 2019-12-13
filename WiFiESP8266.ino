#include <ESP8266WiFi.h> //Incluindo a biblioteca wifi

//Variáveis com o nome da rede e senha
char ssid [] = "BRUNO";
char senha[] = "11235813";

//Definindo o servidor HTTP na porta 80
WiFiServer server(80);

//Aqui vamos criar uma função que irá efetuar a conexão na rede wifi
void conectarWiFi(char SSID[], char SENHA[]){

  Serial.print("Conectando a rede");
  Serial.println(SSID);

  WiFi.begin(SSID, SENHA); //Inicia a conexão WiFi

/*Enquanto o WiFi não conecta ele fica printando um
ponto a cada 0,5s*/
  while(WiFi.status () != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    }
   /*Quando conectar - vai apresentar
   a mensagem e o IP*/
  Serial.println(" ");
  Serial.println("WiFi Conectado");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());
  }

void setup() {

   Serial.begin(115200);
   delay(10);
  //Chama a função dentro do SETUP
  conectarWiFi(ssid, senha);

//Inicializando o servidor
  server.begin();
 //Informando ao usuário que foi inicializado
 Serial.println("Servidor Inicializado");

}

void loop() {
  
  WiFiClient client = server.available();
  if(!client){
    return;
  }

  while(!client.available()){
    delay(1);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta http-equiv='refresh' content='2'>"); //atualiza a página a cada 2s.
  client.println("<h1>Introducao ao IoT com ESP8266</h1>");
  client.println("<h2>Ola!</h2>");
  client.println("</html>"); 

  

}
