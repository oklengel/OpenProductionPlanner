<template>
  <div>
    <h2>About</h2>
    <div class="container" id="notice">
      <span class="sectionHeader">Important:</span>
      <br />
      <ul class>
        <li>This software comes with no warranty</li>
        <li>
          It's illegal to use this software or code in any areas of Russia or
          China
        </li>
      </ul>
    </div>
    <div class="container" id="3rdparty" >
      <span class="sectionHeader">3rd Party Libraries:</span>
      <br/>
        <span class="marked">Frontend</span>
        <ul>
        <li>-https://github.com/vasturiano/timelines-chart-</li>
        <li>https://vuejs.org/</li>
        <li>https://fontawesome.com/</li>
        <li>https://developers.google.com/blockly</li>
        <li>-https://github.com/jerosoler/Drawflow-</li>
        </ul>
        <!--ok-->
        <span class="marked">Backend</span>
        <ul>
        <li>https://github.com/nlohmann/json</li>
        <li>https://github.com/microsoft/cpprestsdk</li>
        <li>https://www.postgresql.org/docs/9.5/libpq.html</li>
        </ul>
        <!--ok-->
        <span class="marked">Database</span>
        <ul>
        <li>Postgresql</li>
        </ul>
        <!--ok-->
        <span class="marked">Misc</span>
        <ul>
        <li>Postman</li>
        <li>DBeaver</li>
        <li>VS Code</li>
        <li>Docker Desktop</li>
      </ul>
      <br/>
      </div>
      <div class="container" id="livesavers">
        <span class="sectionHeader">Special thanks to these guides:</span>
        <ul>
          <li>
            https://awstip.com/a-modern-c-http-server-with-pistache-and-docker-fde07110f2f
          </li>
        </ul>
      
    </div>
  </div>
</template>

<style scoped>
h2 {
  text-decoration-line: underline;
  font-weight: bold;
  font-family: Arial, Helvetica, sans-serif;
}

div {
  text-align: left;
  margin: 0;
  margin-left: 1.5%;
  margin-top: 3%;
}


div>.container{
  margin: 0;
  margin-top: 1%;
}

ul {
  margin: 0%;
}

.sectionHeader {
  margin-left: 0;
  padding-left: 0;
  font-size: larger;
  font-weight: bolder;
  text-decoration: underline;
  text-shadow: 0.5px grey;
}

.marked {
  color: #3a3a3a;
  font-weight: bold;
  margin-left: 1em;
}

#notice {
  background-color: orange;
  padding: 2%;
  border-radius: 5px;
}
</style>

