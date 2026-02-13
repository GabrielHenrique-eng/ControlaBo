#include <WiFi.h>
#include <WebServer.h>

// incluir as informacoes da rede wifi

const char* ssid = "NOME_WIFI"; // nome da rede wifi
const char* password = "SENHA_WIFI"; // senha da rede wifi

WebServer server(80);

bool status_arma = false;

void receberComando() {
  if (server.hasArg("acao")) {
    String comando = server.arg("acao");

    if (comando == "FRENTE") {
      Serial.println("Comando recebido: FRENTE");
    }
    else if (comando == "TRAS") {
      Serial.println("Comando recebido: TRAS");
    }
    else if (comando == "ESQUERDA") {
      Serial.println("Comando recebido: ESQUERDA");
    }
    else if (comando == "DIREITA") {
      Serial.println("Comando recebido: DIREITA");
    }
    else if (comando == "ARMA") {
      if (status_arma) {
        status_arma = false;
        Serial.println("Status Arma: DESLIGADA")
      } else {
        status_arma = true;
        Serial.println("Status Arma: LIGADA");
      }
    } 
    else if (comando == "VRAPIDA") {
      Serial.println("Status Velocidade: RAPIDA");
    }
    else if (comando == "VMEDIA") {
      Serial.println("Status Velocidade: MEDIA");
    }
    else if (comando == "VLENTA") {
      Serial.println("Status Velocidade: LENTA");
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
  Serial.begin(115200);

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
}
