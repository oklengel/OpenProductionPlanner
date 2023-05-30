<script lang="ts">
import SidebarLink from './SidebarLink.vue'
import { collapsed, toggleSidebar, sidebarWidth } from './state.js'
import en from "../../lang/en"
import de from "../../lang/de"
//import est from "../../lang/est"
import esp from "../../lang/esp"
export default {
  props: {},
  components: { SidebarLink },
  setup() {
    return { collapsed, toggleSidebar, sidebarWidth }
  }
}
</script>

<template>
  <div class="sidebar" :style="{ width: sidebarWidth }">
    <h1>
      <span v-if="collapsed">
        <div>O</div>
        <div>P</div>
        <div>P</div>
        <hr/>
      </span>
      <span v-else>Open Production Planner</span>
    </h1>

    <SidebarLink to="/" icon="fas fa-home">Home</SidebarLink>
    <SidebarLink to="/dashboard" icon="fas fa-chart-bar">Dashboard</SidebarLink>
    <SidebarLink to="/production" icon="fas fa-list-check">Production</SidebarLink>
    <SidebarLink to="/recipes" icon="fas fa-flask">Recipes</SidebarLink>
    <SidebarLink to="/ressources" icon="fas fa-warehouse">Ressources</SidebarLink>
    <SidebarLink to="/personal" icon="fas fa-users">Personal</SidebarLink>
    <SidebarLink to="/about" icon="fas fa-book">About</SidebarLink>
    <SidebarLink to="/settings" icon="fas fa-gear">Settings</SidebarLink>

    <span
      class="collapse-icon"
      :class="{ 'rotate-180': collapsed }"
      @click="toggleSidebar"
    >
      <i class="fas fa-angle-double-left" />
    </span>
  </div>
</template>

<style>
:root {
  --sidebar-bg-color: #2f855a;
  --sidebar-item-hover: #38a169;
  --sidebar-item-active: #276749;
}
</style>

<style scoped>
hr{
    margin-top: -0.3em;
}
.sidebar {
  color: white;
  background-color: var(--sidebar-bg-color);
  float: left;
  position: fixed;
  z-index: 1;
  top: 0;
  left: 0;
  bottom: 0;
  padding: 0.5em;
  transition: 0.3s ease;
  display: flex;
  flex-direction: column;
}
.sidebar h1 {
  height: 2.5em;
  padding-bottom: 1em;
}
.collapse-icon {
  position: absolute;
  bottom: 0;
  padding: 0.75em;
  color: rgba(255, 255, 255, 0.7);
  transition: 0.2s linear;
}
.rotate-180 {
  transform: rotate(180deg);
  transition: 0.2s linear;
}
</style>