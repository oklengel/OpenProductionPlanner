<template>
    <div>
      <h1>REST Testing</h1>
      <button @click="testGet">Test GET</button>
      <button @click="testPost">Test POST</button>
      <button @click="testPut">Test PUT</button>
      <button @click="testDelete">Test DELETE</button>
      <div v-if="response">
        <h2>Response:</h2>
        <pre>{{ response }}</pre>
      </div>
    </div>
  </template>
  
  <script>
  import App from '../App.vue';
  export default {
    data() {
      return {
        response: null
      };
    },
    methods: {
      async testGet() {
        try {
          const response = await fetch('http://localhost:8083/test', {
            method: 'GET'
          });
          const contentType = response.headers.get('content-type');
          if (contentType && contentType.includes('application/json')) {
            const data = await response.json();
            this.response = JSON.stringify(data, null, 2);
          } else {
            const data = await response.text();
            this.response = data;
          }
        } catch (error) {
          console.error(error);
        }
      },
      // Restliche Methoden (testPost, testPut, testDelete) hier einfügen
    }
  };
  </script>
  