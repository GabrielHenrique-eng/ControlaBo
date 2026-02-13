#include <WiFi.h>
#include <WebServer.h>

// incluir as informacoes da rede wifi

const char* ssid = "NOME_WIFI"; // nome da rede wifi
const char* password = "SENHA_WIFI"; // senha da rede wifi

WebServer server(80);

bool status_arma = false;

String status_movimento = "NEUTRO";
String status_velocidade = "VMEDIA";

void receberComando() {
  if (server.hasArg("acao")) {
    String comando = server.arg("acao");

    if (comando == "FRENTE") {
      Serial.println("Comando recebido: FRENTE");
      status_movimento = "FRENTE";
    }
    else if (comando == "TRAS") {
      Serial.println("Comando recebido: TRAS");
      status_movimento = "TRAS";
    }
    else if (comando == "ESQUERDA") {
      Serial.println("Comando recebido: ESQUERDA");
      status_movimento = "ESQUERDA";
    }
    else if (comando == "DIREITA") {
      Serial.println("Comando recebido: DIREITA");
      status_movimento = "DIREITA";
    } else if (comando == "NEUTRO") {
      Serial.println("Comando recebido: NEUTRO");
      status_movimento = "NEUTRO";
    }
    else if (comando == "ARMA") {
      if (status_arma) {
        status_arma = false;
        Serial.println("Status Arma: DESLIGADA");
      } else {
        status_arma = true;
        Serial.println("Status Arma: LIGADA");
      }
    } 
    else if (comando == "VRAPIDA") {
      Serial.println("Status Velocidade: RAPIDA");
      status_velocidade = "VRAPIDA";
    }
    else if (comando == "VMEDIA") {
      Serial.println("Status Velocidade: MEDIA");
      status_velocidade = "VMEDIA";
    }
    else if (comando == "VLENTA") {
      Serial.println("Status Velocidade: LENTA");
      status_velocidade = "VLENTA";
    }
    else {
      Serial.println("Comando desconhecido: " + comando);
    }

    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Parametro 'acao' nao encontrado");
  }
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  server.on("/comando", receberComando);
  server.begin();

  Serial.println("Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();

  // lidar com o movimento

}
