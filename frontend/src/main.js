import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import axios from 'axios'
import VueAxios from 'vue-axios'

import '@fortawesome/fontawesome-free/js/all'
//import VueI18n from 'vue-i18n' error?


createApp(App).use(router,VueAxios,axios).mount('#app')
