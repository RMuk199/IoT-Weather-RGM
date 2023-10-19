#define sensor 32
#define dhtSensor 33

#include <WiFi.h>
#include <aREST.h>
#include <DHT.h>
#include <math.h>

#define DHTTYPE DHT11

DHT dht(dhtSensor, DHTTYPE);

const char* ssid = "iinet61384D";
const char* password = "J2Nct8onWn";

#define LISTEN_PORT           80

WiFiServer server(LISTEN_PORT);

aREST rest = aREST();

// Declare the variables for humidity and temperature
float h = 0;
float t= 0;
int val = 0;

void setup() {

  Serial.begin(9600);

  pinMode(12, OUTPUT);

  dht.begin();

  rest.set_id("119");
  rest.set_name("alpha-119");

  // Expose the humidity and temperature variables to the REST API
  rest.variable("humidity", &h);
  rest.variable("temperature", &t);
  rest.variable("water", &val);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  IPAddress ip(192, 168, 1, 119); //set static ip
  IPAddress gateway(192, 168, 1, 1); //set gateway
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
  IPAddress subnet(255, 255, 255, 0); //set subnet
  WiFi.config(ip, gateway, subnet);

  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {

  val = analogRead(sensor);
  Serial.print("Analog Output: ");
  Serial.print(val);

  if (val == 4095) {
    Serial.println("   Status: Dry");
    digitalWrite(12, HIGH);
  } else {
    Serial.println("   Status: Wet");
    digitalWrite(12, LOW);
  }

  // Update the humidity and temperature variables
  h = dht.readHumidity();
  t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);

  

  WiFiClient client = server.available();

  if (!client) {
    delay(1000);
     return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);

  delay(5000);
  
}
