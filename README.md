# ControlaBo

## 📱 Manual de Uso – Controle Robótico via ESP32
🎮 Visão Geral

Este protótipo foi desenvolvido para controlar um robô utilizando um microcontrolador ESP32 conectado via Wi-Fi.
A interface permite controlar movimentação, velocidade e ativar/desativar o mecanismo da arma de forma simples e intuitiva.

## 🕹️ Controles de Movimento

Os botões do lado esquerdo da tela controlam a direção do robô:

Frente → Move o robô para frente.

Trás → Move o robô para trás.

Esquerda → Gira o robô para a esquerda.

Direita → Gira o robô para a direita.

Cada botão envia um comando via rede para o ESP32, que interpreta e executa a ação correspondente.

## ⚙️ Controle da Arma

O botão "Ligar/Desligar Arma" ativa ou desativa o mecanismo da arma do robô.

Ao pressionar, o sistema alterna entre estado ligado e desligado.

O ESP32 recebe o comando e altera o estado do atuador correspondente.

## 🚀 Controle de Velocidade

Na lateral direita da tela, há três opções de velocidade:

Rápida → Define o robô para operar em alta velocidade.

Média → Define velocidade intermediária.

Lenta → Define baixa velocidade para maior controle.

Esses comandos ajustam a potência enviada aos motores.

## 🌐 Comunicação

O aplicativo se comunica com o ESP32 utilizando requisições HTTP via Wi-Fi.

Fluxo de funcionamento:

Usuário pressiona um botão.

O aplicativo envia um comando para o IP do ESP32.

O ESP32 processa o comando.

O robô executa a ação correspondente.

--

## 🌆 Interface Gráfica

<table>
  <tr>
    <td style="vertical-align: middle;">
      <img width="440" height="220" src="https://github.com/user-attachments/assets/50bbdcc9-2102-4bc4-a89b-b52d21d7eb70" />
    </td>
    <td style="vertical-align: middle; padding-left: 20px;">
      Primeiramente, ao abrir o aplicativo, o usuário possui duas opções:
      <br><br>
      • <strong>Tutorial</strong><br>
      • <strong>Iniciar Controle</strong>
    </td>
  </tr>
</table>


---

## 💡 Tela de Tutorial do Controlador

<img width="440" height="220" alt="{4C0A6CFD-1C68-4E2A-B4D0-D3A23AD05F9D}" src="https://github.com/user-attachments/assets/962a3672-a39d-48b7-965e-e56335f46ee2" />
<img width="440" height="220" alt="{FEE220F1-5C2E-4A0F-8874-CA663F497D3E}" src="https://github.com/user-attachments/assets/b8f9e74b-a9b5-488c-afab-0772673e13f6" />
<img width="440" height="220" alt="{1A642E19-DDB2-463E-9E46-014E8F10DA58}" src="https://github.com/user-attachments/assets/3e814af8-16b1-44b8-8b50-e73cb0dabd8e" />

---

## 🎮 Tela do Controle

<table>
  <tr>
    <td style="vertical-align: middle;">
      <img width="440" height="220" src="https://github.com/user-attachments/assets/dbc7f5e5-bd26-49d9-bfaf-3afee6145da2" />
    </td>
    <td style="vertical-align: middle; padding-left: 20px;">
      Esta tela permite que o usuário controle o robô em tempo real.
      <br><br>
      Ela contém:
      <br><br>
      • Botões de movimentação (frente, trás, esquerda e direita);<br>
      • Controle de velocidade (rápida, média e lenta);<br>
      • Botão para ligar ou desligar a arma do robô.
      <br><br>
      Todos os comandos são enviados via Wi-Fi para o ESP32, que executa as ações imediatamente.
    </td>
  </tr>
</table>






