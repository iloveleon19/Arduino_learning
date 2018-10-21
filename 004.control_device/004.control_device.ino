#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <aREST.h>

//Clients
WiFiClient espClient;
PubSubClient client(espClient);

//Create aREST instance
aREST rest = aREST(client);
//Unique ID to identify the device for cloud.arest.io
char* device_id = "IOT_B_5154";

//WiFi parameters
const char* ssid    ="TOTOLINK N302RE";
const char* password="";

//Functions
void callback(char* topic, byte* payload, unsigned int length);

void setup() {
  // start serial
  Serial.begin(115200);

  //set callback
  client.setCallback(callback);

  //Give name and ID to device
  rest.set_id(device_id);
  rest.set_name("devices_control");

  //connect to WiFi
    WiFi.begin(ssid,password);
  //如果網路沒連上，就打出"."
   while (WiFi.status() != WL_CONNECTED)
   {
    delay(500);
    Serial.print(".");
   }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  //打出現在連上去的IP
  Serial.println(WiFi.localIP());
  //打出現在連上去的SSID
  Serial.println(WiFi.SSID());
  delay(1000);

  //set output topic
  char* out_topic = rest.get_topic();
}

void loop() {
  // connect to the cloud
  rest.handle(client);
}

//handles message arrived on subscribed topic (s)
void callback(char* topic, byte* payload, unsigned int length)
{
  rest.handle_callback(client, topic, payload, length);
}
