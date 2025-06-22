 # **Monitoreo Electrónico de Invernadero**
 ## **Informe de Avances**

**Autor**

**Laureano Wawryczuk \- Padrón 102400**

**Fecha: 21/06/2025**

**1er cuatrimestre 2025**

A continuación se detalla el informe de avances del TP4 a partir de los requerimientos

| Estado | Descripción      |
|-----|---------------------|
| 🟢 | Ya implementado |
| 🟡 | En proceso de implementarse |
| 🔴 | No se implementará |

#### **Luz**  

| Req ID | Descripción | Estado | 
|--------|-------------|--------|  
| 1.1    | El sistema deberá poseer un control de iluminación preseteable para mantener un flujo lumínico constante sobre la planta. | 🟢 |  
| 1.2    | El control de la intensidad lumínica debe ajustarse empleando un potenciómetro. | 🟢 |  

#### **Agua**  

| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 2.1    | El sistema tendrá integrado un tanque de agua para el riego. | 🔴 |  
| 2.2    | El tanque dispondrá de un sensor de agua para avisar al usuario que el sistema se quedó sin agua, emitiendo alerta sonora y lumínica| 🟢 |  
| 2.3    | El sistema empleará una electroválvula para el control del riego. | 🟢 |  

#### **Modo de operación**  

| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 3.1    | El sistema operará de forma automática midiendo parámetros del recinto y ajustando las condiciones acorde a la configuración | 🟢 |
| 3.2    | En caso de ausencia de agua el sistema lo indicará al usuario y si ésta persiste bloqueará el sistema hasta que el agua se rellene y se presione el pulsador de reset | 🟢 | 

#### **Display**  

| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 4.1    | El Display mostrará en pantalla 4 menúes que indicarán el estado del sistema y podrá cambiarse entre ellos utilizando un pulsador de Menu | 🟢 | 
| 4.1.1  | -  El primer menú indicará el nombre del sistema.| 🟢 |
| 4.1.2  | -  El segundo mostrará los datos del suelo y del sistema de riego.| 🟢 |
| 4.1.3  | -  El tercero mostrará los datos de temperatura y estado del tanque (lleno o vacío).| 🟢 |
| 4.1.4  | -  El cuarto mostrará el día y la hora configuradas.| 🟢 |
| 4.2    | Si el sistema se queda sin agua durante un tiempo prolongado el Display indicará que el sistema está bloqueado.| 🟢 |

#### **Configuración**
| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 5.1    | Empleando el módulo bluetooth podrán configurarse los parámetros del sistema. | 🟡 |

#### **Protocolo UART**
| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 6.1    | El sistema empleará el protocolo UART para mostrar todos los parámetros del sistema. | 🟢 |
  
#### **Alimentación**
| Req ID | Descripción | Estado |  
|--------|-------------|--------|  
| 7.1    | El sistema debe operar con una fuente conmutada de 12V 1A. | 🟢 |
