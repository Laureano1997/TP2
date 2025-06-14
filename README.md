## Definición de Requisitos y Casos de Uso del Trabajo Final introducción a Sistemas Embebidos  
#### Laureano Agustin Wawryczuk

#### 1er Cuatrimestre 2025  

# Monitoreo Electrónico de Invernadero 

## 1 - Marco del proyecto  

Se desea implementar un sistema que interactúe con diferentes sensores y actuadores, empleando interfacez con el usuario y módulos de comunicación para transmisión de datos para ser utilizados en una aplicación real.

## 2 - Selección del proyecto a implementar  

Al momento de la elección del sistema a implementar, se barajaron diferentes opciones acorde a tres aspectos a considerar:  

- **Disponibilidad del hardware**: Los elementos electrónicos utilizados deben estar disponibles en el mercado. 
- **Utilidad del proyecto**: Se desea que el sistema a implementar tenga utilidad directa.
- **Tiempo de implementación**: El proyecto debe ser implementado en los tiempos explicitados a lo largo del cuatrimestre.

<table>
  <tr>
    <th>Proyecto</th>
    <th>Peso </th>
    <th>Disponibilidad del hardware (Peso: 8)</th>
    <th>Utilidad del proyecto (Peso: 7)</th>
    <th>Tiempo de implementación (Peso: 9)</th>
    <th> Suma de puntajes pesados </th>
  </tr>
  <tr>
    <td rowspan="2">Timbre escolar</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">7</td>
    <td style="text-align: center;">9</td>
    <td style="text-align: center;" rowspan="2">194</td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">64</td>
    <td style="text-align: center;">49</td>
    <td style="text-align: center;">81</td>
</tr>
<tr>
    <td rowspan="2">Invernadero automático</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">8</td>
    <td style="text-align: center;">9</td>
    <td style="text-align: center;" rowspan="2"> 201 </td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">64</td>
    <td style="text-align: center;">56</td>
    <td style="text-align: center;">56</td>
</tr>
<tr>
    <td rowspan="2">Monitoreo de alimentación de tableros industriales</td>
    <td>Puntaje</td> 
    <td style="text-align: center;">4</td>
    <td style="text-align: center;">9</td>
    <td style="text-align: center;">4</td>
    <td style="text-align: center;" rowspan="2"> 131 </td>
  </tr>
  <tr>
    <td> Puntaje pesado</td>
    <td style="text-align: center;">32</td>
    <td style="text-align: center;">63</td>
    <td style="text-align: center;">36</td>
    
</tr>
</table>

-Timbre escolar: El proyecto consiste en implementar un timbre automático para aplicación en colegios secundarios donde se tienen horarios de recreos establecidos, automatizando el proceso de tocar el timbre y evitando errores por parte del preceptor. Se le asignó un puntaje de 8 en disponibilidad de hardware, porque los elementos se consiguen fácilmente en cualquier casa de electrónica; un puntaje de 7 en utilidad, dado que puede generar interés a los colegios pero solo a un costo bajo; se le asignó un puntaje de 9 a tiempo de implementación, porque es un proyecto acorde al tiempo estipulado

-Invernadero automático: El proyecto consiste en implementar un sistema que controle y regule los parámetros dentro de un invernadero para abastecer de agua y monitorear el estado de una planta específica, automatizando el proceso rutinario de una persona de regar el suelo. Se le asignó un puntaje de 8 en disponibilidad de hardware, porque los elementos se consiguen fácilmente en cualquier casa de electrónica; un puntaje de 8 en utilidad, dado que a un precio competitivo puede introducirse en el mercado; se le asignó un puntaje de 9 a tiempo de implementación, porque es un proyecto acorde al tiempo estipulado

-Monitoreo de alimentación de tableros industriales: El proyecto consiste en dearrollar un sistema que monitoree la tensión y corriente trifásica, detecte anomalías y envíe alertas a un sistema central para monitoreo y acción sobre un tablero aplicado a la industria. Se le asignó un puntaje de 4 en disponibilidad de hardware, porque los transductores para mediciones de corrientes trifásicas son dificiles de conseguir; un puntaje de 9 en utilidad, dado que puede ser un elemento de gran utilidad para control y análisis estadístico; se le asignó un puntaje de 4 a tiempo de implementación, pues es un proyecto extenso para desarrollar.

### 2.1 - Propósito del proyecto  

Diseñar un sistema que automatice el proceso de riego y control de un invernadero, dependiendo únicamente de la persona cuando sea necesario rellenar el agua del recipiente que riega el suelo. A su vez enviará datos de temperatura, humedad, estado de los periféricos y alertas al usuario.

### 2.2 - Alcance del proyecto  

El sistema será desarrollado utilizando la placa **NUCLEO-F429ZI**, incluyendo las siguientes funcionalidades:  

1. Control de electroválvula de riego monitoreando la humedad de suelo y la disponibilidad de agua en el tanque empleando un sensor N.O. al fondo del tanque que se cerrará si detecta agua.
2. Visualización del estado del sistema en un LCD.  
3. Interacción mediante un menú UART y Bluetooth para ajustar parámetros y verificar el estado del sistema.  
4. Pulsador para cambiar los datos mostrados en el Display.
5. LED de tanque vacío y buzzer de alarma ante ausencias de agua prolongadas.
6. Pulsador para apagar la alarma sonora al tener ausencia de agua.
7. Control de iluminación para independizar al sistema de la luz solar.

## 3 - Elicitación de Requisitos y Casos de Uso  

### 3.1 - Diagrama de bloques  

Se presenta a continuación el diagrama en bloques del sistema:  
![Error de imagen](BLOQUES_TP4.png)

### 3.2 Análisis de mercado

[RIEG20](https://www.mercadolibre.com.ar/regador-automatico-con-temporizador-gadnic-amplia-aplicacion-color-blanco/p/MLA35355975?highlight=true&searchVariation=MLA35355975&headerTopBrand=true#polycard_client=search-nordic&searchVariation=MLA35355975&wid=MLA2081759612&position=14&search_layout=grid&type=product&tracking_id=ebd19cd4-d13a-406d-aa17-b2a83fbba3ac&sid=search)

[Hunter Xcore4](https://www.mercadolibre.com.ar/kit-de-riego-automatico-hunter-xcore4-con-electrovalvula-pgv100-y-boquilla-psu-04-17a-hunt-kit-programador-psu-17a-25/p/MLA41746686?highlight=false&headerTopBrand=false#polycard_client=search-nordic&searchVariation=MLA41746686&wid=MLA1496301901&position=5&search_layout=grid&type=product&tracking_id=ebd19cd4-d13a-406d-aa17-b2a83fbba3ac&sid=search)

[HTV13FRF](https://articulo.mercadolibre.com.ar/MLA-2018382592-programador-1-zona-hub-wifi-alexa-google-home-rain-point-_JM?variation=182950089014#reco_item_pos=3&reco_backend=pdp_pads_right_rars_v2_with_default&reco_backend_type=low_level&reco_client=pdp-pads-right&reco_id=8a0557be-7f26-4d3f-ac53-82f6e7b6e29c&reco_model=rk_ent_v2_retsys_ads&is_advertising=true&ad_domain=PDPDESKTOP_RIGHT&ad_position=4&ad_click_id=NjcyNGNhOGYtMmQ3Zi00YjA1LTk2YTEtYTk3NzMyYjExMjI3)

Se analizan tres opciones de controladores para sistemas de tratamiento.

| Característica |  RIEG20 | Hunter Xcore4| HTV13FRF|
|----------------|-----------------|---------|----------------------|
|Pantalla LCD|No|Sí|No|
|Conexión Wireless|No|No|Sí|
|Tanque de agua|No|No|No|
|RTC|No|Sí|No|
|Batería|Sí|No|Sí|
|Control de luz|No|No|No|
|precio|US$18|US$435|110$|

Nota: Los precios se muestran en dolares.

### 3.2 Requerimientos  

A continuación, se enumeran los requerimientos del sistema:  

#### **Luz**  

| Req ID | Descripción |  
|--------|-------------|  
| 1.1    | El sistema deberá poseer un control de iluminación preseteable para mantener un flujo lumínico constante sobre la planta. |  
| 1.2    | El control de la intensidad lumínica debe ajustarse empleando un potenciómetro. |  

#### **Agua**  

| Req ID | Descripción |  
|--------|-------------|  
| 2.1    | El sistema tendrá integrado un tanque de agua para el riego. |  
| 2.2    | El tanque dispondrá de un sensor de agua para avisar al usuario que el sistema se quedó sin agua, emitiendo alerta sonora y lumínica|  
| 2.3    | El sistema empleará una electroválvula para el control del riego. |  

#### **Modo de operación**  

| Req ID | Descripción |  
|--------|-------------|  
| 3.1    | El sistema operará de forma automática midiendo parámetros del recinto y ajustando las condiciones acorde a la configuración |
| 3.2    | En caso de ausencia de agua el sistema lo indicará al usuario y si ésta persiste bloqueará el sistema hasta que el agua se rellene y se presione el pulsador de reset |  

#### **Display**  

| Req ID | Descripción |  
|--------|-------------|  
| 4.1    | El Display mostrará en pantalla 4 menúes que indicarán el estado del sistema y podrá cambiarse entre ellos utilizando un pulsador de Menu |  
| 4.1.1  | -  El primer menú indicará el nombre del sistema.|
| 4.1.2  | -  El segundo mostrará los datos del suelo y del sistema de riego.|
| 4.1.3  | -  El tercero mostrará los datos de temperatura y estado del tanque (lleno o vacío).|
| 4.1.4  | -  El cuarto mostrará el día y la hora configuradas.|
| 4.2    | Si el sistema se queda sin agua durante un tiempo prolongado el Display indicará que el sistema está bloqueado.|

#### **Configuración**
| Req ID | Descripción |  
|--------|-------------|  
| 5.1    | Empleando el módulo bluetooth podrán configurarse los parámetros del sistema. | 

#### **Protocolo UART**
| Req ID | Descripción |  
|--------|-------------|  
| 6.1    | El sistema empleará el protocolo UART para mostrar todos los parámetros del sistema. |
  
#### **Alimentación**
| Req ID | Descripción |  
|--------|-------------|  
| 7.1    | El sistema debe operar con una fuente conmutada de 12V 1A. |

### 3.3 Casos de Uso  

A continuación, se detallan algunos casos de uso:  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | El usuario desea cambiar de menú. |  
| **Precondición**          | El sistema no está bloqueado. |  
| **Flujo básico**          | La información del display cambia con el pulsador. |  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | El usuario quiere configurar los parámetros por Bluetooth. |  
| **Precondición**          | El sistema no está bloqueado. |  
| **Flujo básico**          | El sistema toma los datos enviados y los guarda. | 

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | El suelo se encuentra seco. |  
| **Precondición**          | El tanque posee agua para regar. |  
| **Flujo básico**          | Se abre la electroválvula hasta obtener el nivel de humedad configurado. |  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | El sistema se quedó sin agua por una hora. |  
| **Precondición**          | Tanque de agua vacío. |  
| **Flujo básico**          | El sistema se bloquea. |  

| Elemento del caso de uso | Definición |  
|---------------------------|------------|  
| **Disparador**           | El usuario quiere desbloquear el sistema presionando el pulsador de reset. |  
| **Precondición**          | Sistema bloqueado. |  
| **Flujo básico**          | El sistema se desbloquea manteniendo el led de falta de agua encendido. |  

### Plazos  

| Fecha límite             | Entregable |  
|---------------------------|------------|  
| 7 de junio          | Definición de requisitos. |  
| 21 de junio          | Informe de avance. |  
| 28 de junio          | Video del sistema funcionando. |
| 5 de julio          | Informe final del proyecto. |  

